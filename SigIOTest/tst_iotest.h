#ifndef TST_BASEIOTEST_H
#define TST_BASEIOTEST_H
#include <QtTest>
#include <SigIO.h>
class IOTest : public QObject
{
    Q_OBJECT

public:
    IOTest();
    ~IOTest();
    Record r1;
    Record r2;
    Record* readr1;
    Record* readr2;
    SigFileIO* fio;
	
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_write();
    void test_read();

};
#endif // TST_BASEIOTEST_H
