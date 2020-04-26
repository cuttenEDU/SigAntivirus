#undef QT_TESTCASE_BUILDDIR


// add necessary includes here
#include <tst_iotest.h>



IOTest::IOTest()
{

}

IOTest::~IOTest()
{

}

void IOTest::initTestCase()
{
    //char* name = "hello";
    r1 = { 0,6,new char[6] {"hello"},32, "prefix","hash",20,30 };
    r1.recLen = sizeof(r1);
    r2 = { 0,13,new char[12] {"hello world"},32, "prefix","hash",20,30 };
    r2.recLen = sizeof(r2);
    fio = new SigFileIO(QString("base.edb"));
}

void IOTest::cleanupTestCase()
{

}

void IOTest::test_write()
{
    QCOMPARE(fio->writeRecord(r1),0);
    QCOMPARE(fio->writeRecord(r2),0);
}

void IOTest::test_read()
{
    readr1 = fio->readRecord(1);
    readr2 = fio->readRecord(2);
    QDebug(readr1->toString());
    QDebug(readr2->toString());
    QCOMPARE(QString(*readr1->name), QString(r1.name));
    QCOMPARE(QString(*readr2->name), QString(r2.name));
}

//QTEST_APPLESS_MAIN(BaseIOTest)
QTEST_MAIN(IOTest)

//#include "tst_baseiotest.moc"
