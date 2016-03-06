#include <httpd.h>
#include <http_config.h>
#include <http_protocol.h>
#include <http_log.h>

extern "C" module AP_MODULE_DECLARE_DATA helloworld_module;

APLOG_USE_MODULE (helloworld);

static int helloworld_handler(request_rec *r) {
    if (strcmp(r->handler, "helloworld")) {
        return DECLINED;
    }
    r->content_type = "text/html";      
 
    if (!r->header_only) {
        ap_rputs("The sample page from mod_hello_world.c\n", r);
    }
    return OK;
}

static void helloworld_register_hooks(apr_pool_t *p) {
    ap_hook_handler(helloworld_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA helloworld_module = { STANDARD20_MODULE_STUFF, NULL, /* create per-dir    config structures */
NULL, /* merge  per-dir    config structures */
NULL, /* create per-server config structures */
NULL, /* merge  per-server config structures */
NULL, /* table of config file commands       */
helloworld_register_hooks /* register hooks                      */
};

