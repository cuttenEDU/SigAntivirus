#ifndef TST_BASEIOTEST_H
#define TST_BASEIOTEST_H
#include <QtTest>
#include <sigbaseio.h>
class BaseIOTest : public QObject
{
    Q_OBJECT

public:
    BaseIOTest();
    ~BaseIOTest();
    SigBaseIO s;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();

};
#endif // TST_BASEIOTEST_H
