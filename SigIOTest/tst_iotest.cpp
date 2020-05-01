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
    QFile::remove("base.edb");
    //char* name = "hello";
    //r1=Record();
    //r1._recLen = sizeof(r1);
    r1 = new Record(new QString("cool record"), 100, new QByteArray("prefix", PREF_SIZE), new QByteArray("hash", HASH_SIZE), 20, 40);
	r2 = new Record(new QString("cool record 2"), 200, new QByteArray("prefix 2", PREF_SIZE), new QByteArray("hash 2", HASH_SIZE), 233, 412);
    //qDebug() << *r1->toString();
	qDebug() << *r1->getName();
    qDebug() << *r2->getName();
    //r2 = { 0,13,new char[12] {"hello world"},32, "prefix","hash",20,30 };
    //r2.recLen = sizeof(r2);
    fio = new SigFileIO(QString("base.edb"));
	
}

void IOTest::cleanupTestCase()
{
    QFile::remove("base.edb");
}

void IOTest::test_write()
{
    QCOMPARE(fio->writeRecord(r1),0);
    //QCOMPARE(fio->writeRecord(r2),0);
}

void IOTest::test_read()
{
    readr1 = fio->readRecord(1);
    readr2 = fio->readRecord(2);
    //readr2 = fio->readRecord(2);
    qDebug() << *r1->getName();
    qDebug() << *r2->getName();
    //qDebug() << readr2->name;
    QCOMPARE(readr1->getRawName(), r1->getRawName());
    QCOMPARE(readr1->getRawName(), r1->getRawName());
}

//QTEST_APPLESS_MAIN(BaseIOTest)
QTEST_MAIN(IOTest)

//#include "tst_baseiotest.moc"
