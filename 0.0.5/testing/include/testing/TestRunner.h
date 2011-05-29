// $Id$
#ifndef TESTING_TESTRUNNER_H
#define TESTING_TESTRUNNER_H

#include "testing/Test.h"
#include "testing/TestList.h"
#include "testing/CurrentTest.h"

namespace testing {

class TestReporter;
class TestResults;
class Timer;

int RunAllTests();

struct True
{
    bool operator()(const Test* const) const
    {
        return true;    
    }
};

class TestRunner
{
public:
    explicit TestRunner(TestReporter& reporter);
    ~TestRunner();

    template<class Predicate>
    int RunTestsIf(
            TestList const& list,
            char const* suiteName, 
            const Predicate& predicate,
            int maxTestTimeInMs) const
    {
        Test* curTest = list.GetHead();

        while (curTest != 0) {
            if (IsTestInSuite(curTest, suiteName) && predicate(curTest)) {
                RunTest(m_result, curTest, maxTestTimeInMs);
            }

            curTest = curTest->next;
        }

        return Finish();
    }   

private:
    TestReporter* m_reporter;
    TestResults* m_result;
    Timer* m_timer;

    int Finish() const;
    bool IsTestInSuite(const Test* const curTest, char const* suiteName) const;
    void RunTest(TestResults* const result, Test* const curTest, int const maxTestTimeInMs) const;
};

}//namespace testing
#endif