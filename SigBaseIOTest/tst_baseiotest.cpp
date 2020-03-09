#undef QT_TESTCASE_BUILDDIR
#include <QtTest>

// add necessary includes here
#include "sigbaseio.h"

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

BaseIOTest::BaseIOTest()
{

}

BaseIOTest::~BaseIOTest()
{

}

void BaseIOTest::initTestCase()
{

}

void BaseIOTest::cleanupTestCase()
{

}

void BaseIOTest::test_case1()
{
    
    QCOMPARE(s.return2(), 2);
}

void BaseIOTest::test_case2()
{
    qDebug() << s.returnhw().c_str();
    QCOMPARE(s.returnhw(), std::string("Hella world!"));
}

QTEST_APPLESS_MAIN(BaseIOTest)

#include "tst_baseiotest.moc"
