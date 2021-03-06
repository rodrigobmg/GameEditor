#pragma once

#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <iterator>
#include "InputListener.h"
#include "StaticGameObject.h"

class Logger;
class Camera;
class AddOrEditSGOOnMapDialog;
class AddOrEditPointLightOnMapDialog;
class GEMath;
class MapEditorViewModel;
class StaticGameObjectDbInfo;
class MapEditorPreferences;
class PointLightDbInfo;

class MapEditorControl :
  public InputListener
{
public:
  static const int NOTHING_SELECTED = -1;
protected:
  Camera* m_camera;

  MapEditorViewModel* m_mapEditorViewModel;
  std::set<int>* m_selectedObjectIds;
  std::map<int, StaticGameObject>* m_staticGameObjectMap;
  
  std::vector<StaticGameObject*>* m_visibleSgos;
  MapEditorPreferences* m_mapEditorPreferences;

  XMVECTOR m_rotateAroundPoint;
  bool m_needRecalculateRotationAroundPoint = true;
  bool m_sgoRotated;
  bool m_sgoTranslated;
  float m_timeInSecondsBetweenFrames;

  XMFLOAT3 m_accumulativePositionForSnap;
  bool m_needRecalculateAcumulativePositionForSnap = true;

  XMFLOAT3 m_accumulativeRotationForSnap;
  bool m_needRecalculateAcumulativeRotationForSnap = true;
public:
  bool m_objectsCountInVisibleAreaWasChanged = true;
protected:
  bool RayAABBIntersect(XMFLOAT3& minPoint, XMFLOAT3& maxPoint, XMFLOAT3& position, XMFLOAT3& direction, float& result);
  void PickObject(const InputState* inputState, int mouseXCoor, int mouseYCoor);
  void RotateCamera(const InputState* inputState);
  void MoveCamera(const InputState* inputState);
  void RotateObjects(const InputState* inputState);
  void MoveObjects(const InputState* inputState);

  void RotateCameraAroundObject(const InputState* inputState);

  XMMATRIX GetCameraMatrixRotateAroundTarget(XMVECTOR cameraPosition, XMVECTOR targetPoint, float deltaXRadians, float deltaYRadians);

  float GetCorrectedWithSnapCoord(float coord, float snapSize);
  void Clone();
  void Delete();
  XMFLOAT3 GetCenterOfSelectedObjects(bool isChangeObjectOperation);
  void SaveChangedPositionsInDB();
  void SaveChangedRotationsInDB();
  void CalculateDifferenceWithPoint(std::map<int, XMFLOAT3>* differenceFromPoint, XMFLOAT3 point);

  bool AllSelectedObjectsAreFrozen();

  void EditSgoOnMap(int id);
  void EditPointLightOnMap(int id);
  void CloneSgo(int id);
  void ClonePointLight(int id);
  void DeleteSgo(int id);
  void DeletePointLight(int id);
public:
  MapEditorControl(MapEditorViewModel* mapEditorViewModel, std::vector<StaticGameObject*>* visibleSgos, Camera* camera);
  virtual ~MapEditorControl();

  virtual void ProcessUserInput(const InputState* inputState) override;

  MapEditorViewModel* GetMapEditorViewModel() { return m_mapEditorViewModel; }

  void AddSgoToMap(const StaticGameObjectDbInfo& sgo);
  void AddPointLightToMap(PointLightDbInfo& pointLight);
  void EditGameObject(int id);
  void Delete(std::vector<int>& ids);
  void Clone(std::vector<int>& ids);

  void FreezeAll();
  void UnfreezeAll();
};

