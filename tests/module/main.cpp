#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>

using namespace ApprovalTests;

auto directoryDisposer = Approvals::useApprovalsSubdirectory("approval");
auto frontLoadedReportDisposer = Approvals::useAsFrontLoadedReporter(BlockingReporter::onMachineNamed("CIRCLECI"));
