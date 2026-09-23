// Stub implementation of crl::on_main_update_requests() for UzOS build
// The real implementation lives in Telegram's sandbox.cpp.
// We provide a simple inline version using rpl::never<>() here.
#include <crl/crl_on_main.h>

#ifdef CRL_ENABLE_RPL_INTEGRATION
#include <rpl/rpl.h>

namespace crl {

rpl::producer<> on_main_update_requests() {
    return rpl::never<rpl::empty_value>();
}

} // namespace crl
#endif // CRL_ENABLE_RPL_INTEGRATION
