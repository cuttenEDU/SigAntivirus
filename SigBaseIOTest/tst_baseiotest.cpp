#undef QT_TESTCASE_BUILDDIR


// add necessary includes here
#include <tst_baseiotest.h>



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

//QTEST_APPLESS_MAIN(BaseIOTest)
QTEST_MAIN(BaseIOTest)

//#include "tst_baseiotest.moc"
