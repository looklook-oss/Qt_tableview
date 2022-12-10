#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_standard_data_model = new QStandardItemModel(this);
    //设置表格标题行
    m_standard_data_model->setHorizontalHeaderLabels(QStringList() << "序列号" << "姓名" << "年龄" << "分数");
    //不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置model
    ui->tableView->setModel(m_standard_data_model);
    //自适应所有列 ，让布满空间
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //去掉自动序号列
    ui->tableView->verticalHeader()->setHidden(true);

    for(int i = 0; i < 38; ++i)
    {
        Data data;
        data.name = "姓名" + QString::number(i);
        data.age = "年龄" + QString::number(i*2);
        data.score = QString::number(i+1);

        m_data_list.append(data);
    }
    ui->previous_btn->setEnabled(false);
    connect(ui->previous_btn,&QPushButton::clicked,this,&Widget::on_pushButton_previousPage_clicked);
    connect(ui->next_btn,&QPushButton::clicked,this,&Widget::on_pushButton_nextPage_clicked);
    updateTableData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_previousPage_clicked()
{
    if(m_cur_page >= 1)
    {
        m_cur_page--;
        updateTableData();

        ui->next_btn->setEnabled(true);
        if(m_cur_page <= 0)
        {
            ui->previous_btn->setEnabled(false);
        }
    }
    else
    {
        ui->previous_btn->setEnabled(false);
    }
}

void Widget::on_pushButton_nextPage_clicked()
{
    if(m_cur_page*m_max_page_num < m_data_list.size())
    {
        m_cur_page++;
        updateTableData();
        ui->previous_btn->setEnabled(true);
        if((m_cur_page+1)*m_max_page_num >= m_data_list.size())
        {
            ui->next_btn->setEnabled(false);
        }
    }
    else
    {
        ui->next_btn->setEnabled(false);
    }
}

void Widget::updateTableData()
{
    bool isok;
    qInfo() << "m_cur_page = "  << m_cur_page;
    if((m_data_list.size()/m_max_page_num) > (m_cur_page+1))
    {
        isok = m_standard_data_model->removeRows(0,m_max_page_num);
    }else
    {
        isok = m_standard_data_model->removeRows(0,m_data_list.size()%m_max_page_num);
    }
    int row_index = 0;
    qInfo() << "updateTableData isok = " << isok;
    for(int i_row = m_cur_page*m_max_page_num; i_row < (m_cur_page+1)*m_max_page_num;++i_row)
    {
        if(m_data_list.size() > i_row)
        {
            //序列号
            QStandardItem * index_item = new QStandardItem(QString::number(i_row+1));
            //姓名
            QStandardItem * name_item = new QStandardItem(m_data_list.at(i_row).name);
            //年龄
            QStandardItem * age_item = new QStandardItem(m_data_list.at(i_row).age);
            //分数
            QStandardItem * score_item = new QStandardItem(m_data_list.at(i_row).score);

            m_standard_data_model->setItem(row_index, 0, index_item);
            m_standard_data_model->setItem(row_index, 1, name_item);
            m_standard_data_model->setItem(row_index, 2, age_item);
            m_standard_data_model->setItem(row_index, 3, score_item);

            row_index++;
        }
    }
}

