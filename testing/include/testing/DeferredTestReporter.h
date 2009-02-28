// $Id$
#ifndef TESTING_DEFERREDTESTREPORTER_H
#define TESTING_DEFERREDTESTREPORTER_H

#include "TestReporter.h"
#include "DeferredTestResult.h"
#include <vector>

namespace testing {

class DeferredTestReporter: public TestReporter
{
public:
    virtual void ReportTestStart(TestDetails const& details);
    virtual void ReportFailure(TestDetails const& details, char const* failure);
    virtual void ReportTestFinish(TestDetails const& details, float secondsElapsed);

    typedef std::vector<DeferredTestResult> DeferredTestResultList;
    DeferredTestResultList& GetResults();

private:
    DeferredTestResultList m_results;
};

}//namespace testing
#endif
