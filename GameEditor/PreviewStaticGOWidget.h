#pragma once

#include <QDialog>
#include "ui_PreviewStaticGOWidget.h"
#include <QMessageBox>
#include <memory>
#include "PreviewGameObject.h"
#include "StaticGameObjectDbInfo.h"
#include "QtUtils.h"
#include "QtDirectXWidget.h"

class PreviewStaticGOWidget : public QtDirectXWidget, public Ui::PreviewStaticGOWidget
{
    Q_OBJECT
private:
  StaticGameObject m_sgo;
protected:
  /** Destroys the D3D environment */
  void Shutdown();

  /** paints the scene */
  virtual void paintEvent(QPaintEvent* pEvent) override;
public:
  PreviewStaticGOWidget(QString pathToModels, QString pathToMaterials, QWidget *parent = Q_NULLPTR);
  ~PreviewStaticGOWidget();
  /** Initialized the D3D environment */
  bool Initialize(int screenWidth, int screenHeight, HWND hwnd, std::string pathToMaterials);
  void SetStaticGameObject(StaticGameObjectDbInfo staticGameObject);
};