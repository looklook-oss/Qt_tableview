#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //每行数据展示
    struct Data{
        QString name;
        QString age;
        QString score;
    };

private slots:
    void on_pushButton_previousPage_clicked();
    void on_pushButton_nextPage_clicked();
private:
    //更新数据
     void updateTableData();

private:
    Ui::Widget *ui;
    QStandardItemModel *m_standard_data_model;//数据模型
    QList<Data> m_data_list;   //装载数据

    int m_cur_page = 0;  //当前页
    int m_max_page_num = 10; //一页最大数，行数

};
#endif // WIDGET_H
