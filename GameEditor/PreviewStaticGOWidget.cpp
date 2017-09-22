#include "PreviewStaticGOWidget.h"



PreviewStaticGOWidget::PreviewStaticGOWidget(QString pathToModels, QString pathToMaterials, QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    this->setWindowFlags(Qt::Window);

    //I dont know what it do? but it is for Qt working
    setMinimumSize(m_minWidth, m_minHeight);
    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setAttribute(Qt::WA_PaintOnScreen, true);
    setAttribute(Qt::WA_NativeWindow, true);
   
    SetPathToModels(pathToModels);
    SetPathToMaterials(pathToMaterials);

    bool result = Initialize(width(), height(), (HWND)winId(), m_pathToMaterials);
    if (!result) {
      QMessageBox::critical(this,
        "ERROR",
        "Faild initialize QD3Dwidget",
        QMessageBox::Ok);
    }
}

PreviewStaticGOWidget::~PreviewStaticGOWidget()
{
  Shutdown();
}

void PreviewStaticGOWidget::SetStaticGameObject(StaticGameObjectDbInfo staticGameObject)
{
  m_model = m_graphicSystem->GetModelFactory()->GetResource(m_pathToModels + FileProcessor::FILE_SEPARATOR + staticGameObject.modelFileName.toStdString());
}

bool PreviewStaticGOWidget::Initialize(int screenWidth, int screenHeight, HWND hwnd, std::string pathToMaterials)
{
  bool result;

  HighPerformanceTimer::get().Initialize();
  HighPerformanceTimer::get().Frame();

  m_shaderConfiguration = std::unique_ptr<ShaderConfiguration>(new ShaderConfiguration());
  m_shaderConfiguration->Configure();

  m_graphicSystem = std::unique_ptr<GraphicSystem>(new GraphicSystem);
  if (!m_graphicSystem)
    return false;

  m_graphicSystem->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, m_shaderConfiguration.get(), pathToMaterials);

  // Create the camera object.
  m_Camera = std::unique_ptr<Camera>(new Camera(screenWidth, screenHeight, SCREEN_NEAR, SCREEN_DEPTH));
  if (!m_Camera)
  {
    return false;
  }

  m_Camera->SetPosition(0.0f, 0.0f, -50.0f);

  m_lightininigSystem = std::unique_ptr<LightininigSystem>(new LightininigSystem());
  if (!m_lightininigSystem)
  {
    return false;
  }
  m_lightininigSystem->SetDirectLightDirection(1.0f, 0.0f, 1.0f);
  m_lightininigSystem->SetDirectLightColor(1.0f, 1.0f, 1.0f, 1.0f);
  m_lightininigSystem->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);

  m_inputSystem = std::unique_ptr<InputSystem>(new InputSystem());
  m_inputSystem->Initialize(GetModuleHandle(NULL), hwnd);

  PreviewGameObject* previewGameObject = new PreviewGameObject();
  previewGameObject->SetCamera(m_Camera.get());
  previewGameObject->SetModel(m_model);
  m_inputSystem->AddInputListener(previewGameObject);

  return true;
}

void PreviewStaticGOWidget::Shutdown()
{

}

void PreviewStaticGOWidget::paintEvent(QPaintEvent* evt) {
  HighPerformanceTimer::get().Frame();

  m_inputSystem->Frame();
  std::vector<Model*> renderedModels;
  renderedModels.push_back(m_model);
  m_graphicSystem->DrawModels(renderedModels, m_Camera.get(), m_lightininigSystem.get());

  // trigger another update as soon as possible 
  update();
}