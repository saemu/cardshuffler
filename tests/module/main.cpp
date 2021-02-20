#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>

using namespace ApprovalTests;
namespace {
const auto directoryDisposer = Approvals::useApprovalsSubdirectory("approval");
}  // namespace
