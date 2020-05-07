#undef QT_TESTCASE_BUILDDIR


// add necessary includes here
#include <tst_iotest.h>


IOTest::IOTest() {

}

IOTest::~IOTest() {

}

void IOTest::initTestCase() {
	QFile::remove("base.edb");
	r1 = new Record(new QString("cool record"), 100, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'), 20,
	                40);
	r2 = new Record(new QString("cool record 22"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
	                233, 412);
	r3 = new Record(new QString("cool record 33"), 100, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'), 20,
	                40);
	r4 = new Record(new QString("cool record 44"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
	                233, 412);
	QString str = *r1->toString();
	qDebug() << str.toStdString().c_str();
	qDebug() << *r1->getHash();
	qDebug() << *r2->getName();
	fio = new SigFileIO(QString("base.edb"), this);

}

void IOTest::cleanupTestCase() {
	QFile::remove("base.edb");

}

void IOTest::test_write() {
	QCOMPARE(fio->writeRecord(r1), 0);
	QCOMPARE(fio->writeRecord(r2), 0);
	//QCOMPARE(fio->writeRecord(r1), 0);
	//QCOMPARE(fio->writeRecord(r2), 0);
}

void IOTest::test_read() {
	readr1 = fio->readRecord(0);
	readr2 = fio->readRecord(1);
	readr3 = fio->readRecord(5);
	qDebug() << *readr1->getName();
	qDebug() << *readr2->getName();
	qDebug() << *r1->getName();
	qDebug() << *r2->getName();
	QCOMPARE(readr1->getRawName(), r1->getRawName());
	QCOMPARE(readr1->getRawName(), r1->getRawName());
	qDebug() << readr3;
	QCOMPARE(readr3, nullptr);
}

//QTEST_APPLESS_MAIN(BaseIOTest)
QTEST_MAIN(IOTest)

//#include "tst_baseiotest.moc"
