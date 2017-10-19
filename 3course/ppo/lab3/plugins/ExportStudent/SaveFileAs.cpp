#include "SaveFileAs.h"
#include "ExportStudentComand.h"
#include "TreeModel.h"

#include "ui_saveFile.h"

SaveFileAs::SaveFileAs(QModelIndex index, TreeModel* _treeModel, QUndoStack* _undoStack, QWidget* parent)
    : m_parent(index)
    , QDialog(parent)
    , ui(new Ui::saveFile)
    , treeModel(_treeModel)
    , undoStack(_undoStack)
{
    ui->setupUi(this);
}

SaveFileAs::~SaveFileAs()
{
    delete ui;
}


void SaveFileAs::on_m_cancel_clicked()
{
    this->close();
}

void SaveFileAs::on_m_ok_clicked()
{
    QString filename = ui->m_filename->text();
   ExportStudentComand* exportComand= new ExportStudentComand(m_parent,filename, treeModel);
   //  ExportStudentComand* exportComand= new ExportStudentComand(filename);
   std::cout<<"after export comand"<<std::endl;
    this->close();
   undoStack->push(exportComand);
}