#pragma once

#include "GETable.h"
#include "ISGOOnMapService.h"

class SGOOnMapTM : public GETable<SGOOnMapDbInfo>
{
  Q_OBJECT
protected:
  ISGOOnMapService* m_SGOOnMapService;
  std::string m_SGONameFilter = "";
  std::string m_instanceNameFilter = "";

protected:
  virtual void FillOrderFieldMap() override;
  virtual void GetData() override;

  virtual void appendEntity(SGOOnMapDbInfo& gameObject) override;
  virtual void editEntity(SGOOnMapDbInfo& gameObject) override;
  virtual void removeEntity(int id) override;
public:
  SGOOnMapTM(int onPage = 10, QObject *parent = {});
  virtual ~SGOOnMapTM();
  int columnCount(const QModelIndex &) const override { return 9; }
  QVariant data(const QModelIndex &index, int role) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
  void UpdateTable(int pageNumber, int onPage, int orderFieldIndex, Qt::SortOrder orderDirection, QString SGONameFilter = "", QString instanceNameFilter = "");
  ISGOOnMapService* GetSGOOnMapService() { return m_SGOOnMapService; }
  virtual SGOOnMapDbInfo GetEntityByKey(int id) override;
};