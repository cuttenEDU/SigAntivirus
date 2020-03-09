#include <QtTest>

// add necessary includes here

class BaseIOTest : public QObject
{
    Q_OBJECT

public:
    BaseIOTest();
    ~BaseIOTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

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

}

QTEST_APPLESS_MAIN(BaseIOTest)

#include "tst_baseiotest.moc"
