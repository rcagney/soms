// FOptionContainer class - contains the options for a filter group,
// including the banned/grey/exception site lists and the content/site/url regexp lists

// For all support, instructions and copyright go to:
// http://e2guardian.org/
// Released under the GPL v2, with the OpenSSL exception described in the README file.

#ifndef __HPP_FOPTIONCONTAINER
#define __HPP_FOPTIONCONTAINER

// INCLUDES

#include "String.hpp"
#include "HTMLTemplate.hpp"
#include "ListContainer.hpp"
#include "LanguageContainer.hpp"
#include "ImageContainer.hpp"
#include "RegExp.hpp"
#include <string>
#include <deque>

// DECLARATIONS

std::deque<String> *ipToHostname(const char *ip);

class FOptionContainer
{

    public:
    int reporting_level;
    int category_threshold;
    bool infection_bypass_errors_only;
    bool disable_content_scan;
    int weighted_phrase_mode;
    int group_mode;
    int embedded_url_weight;
    int naughtyness_limit;
    int searchterm_limit;
    bool createlistcachefiles;
    bool enable_PICS;
    bool enable_regex_grey;
    bool enable_ssl_legacy_logic;
    bool enable_local_list;
    off_t max_upload_size;
    bool deep_url_analysis;
    int filtergroup;
    bool non_standard_delimiter;

    //SSL certificate checking
    bool ssl_check_cert;

    //SSL Man in the middle
    bool ssl_mitm;
    bool only_mitm_ssl_grey;
    bool mitm_check_cert;

#ifdef ENABLE_EMAIL
    // Email notification patch by J. Gauthier
    bool notifyav;
    bool notifycontent;
    bool use_smtp;
    int violations;
    int current_violations;
    int threshold;
    long threshold_stamp;
    bool byuser;
#endif

    // File filtering mode - should banned or exception lists be used?
    // if true, use exception lists & exception file site list; otherwise,
    // use banned MIME type & extension lists.
    bool block_downloads;

    bool reverse_lookups;
    bool force_quick_search;
    int bypass_mode;
    int infection_bypass_mode;
    int pics_rsac_violence;
    int pics_rsac_sex;
    int pics_rsac_nudity;
    int pics_rsac_language;
    int pics_icra_chat;
    int pics_icra_moderatedchat;
    int pics_icra_languagesexual;
    int pics_icra_languageprofanity;
    int pics_icra_languagemildexpletives;
    int pics_icra_nuditygraphic;
    int pics_icra_nuditymalegraphic;
    int pics_icra_nudityfemalegraphic;
    int pics_icra_nuditytopless;
    int pics_icra_nuditybottoms;
    int pics_icra_nuditysexualacts;
    int pics_icra_nudityobscuredsexualacts;
    int pics_icra_nuditysexualtouching;
    int pics_icra_nuditykissing;
    int pics_icra_nudityartistic;
    int pics_icra_nudityeducational;
    int pics_icra_nuditymedical;
    int pics_icra_drugstobacco;
    int pics_icra_drugsalcohol;
    int pics_icra_drugsuse;
    int pics_icra_gambling;
    int pics_icra_weaponuse;
    int pics_icra_intolerance;
    int pics_icra_badexample;
    int pics_icra_pgmaterial;
    int pics_icra_violencerape;
    int pics_icra_violencetohumans;
    int pics_icra_violencetoanimals;
    int pics_icra_violencetofantasy;
    int pics_icra_violencekillinghumans;
    int pics_icra_violencekillinganimals;
    int pics_icra_violencekillingfantasy;
    int pics_icra_violenceinjuryhumans;
    int pics_icra_violenceinjuryanimals;
    int pics_icra_violenceinjuryfantasy;
    int pics_icra_violenceartisitic;
    int pics_icra_violenceeducational;
    int pics_icra_violencemedical;
    int pics_icra_violencesports;
    int pics_icra_violenceobjects;
    int pics_evaluweb_rating;
    int pics_cybernot_sex;
    int pics_cybernot_other;
    int pics_safesurf_agerange;
    int pics_safesurf_profanity;
    int pics_safesurf_heterosexualthemes;
    int pics_safesurf_homosexualthemes;
    int pics_safesurf_nudity;
    int pics_safesurf_violence;
    int pics_safesurf_sexviolenceandprofanity;
    int pics_safesurf_intolerance;
    int pics_safesurf_druguse;
    int pics_safesurf_otheradultthemes;
    int pics_safesurf_gambling;
    int pics_weburbia_rating;
    int pics_vancouver_multiculturalism;
    int pics_vancouver_educationalcontent;
    int pics_vancouver_environmentalawareness;
    int pics_vancouver_tolerance;
    int pics_vancouver_violence;
    int pics_vancouver_sex;
    int pics_vancouver_profanity;
    int pics_vancouver_safety;
    int pics_vancouver_canadiancontent;
    int pics_vancouver_commercialcontent;
    int pics_vancouver_gambling;

    // new Korean PICS support
    int pics_icec_rating;
    int pics_safenet_nudity;
    int pics_safenet_sex;
    int pics_safenet_violence;
    int pics_safenet_language;
    int pics_safenet_gambling;
    int pics_safenet_alcoholtobacco;

    std::string name;
    std::string magic;
    std::string imagic;
    std::string cookie_magic;
    std::string mitm_magic;

#ifdef ENABLE_EMAIL
    // Email notification patch by J. Gauthier
    std::string mailfrom;
    std::string avadmin;
    std::string contentadmin;
    std::string avsubject;
    std::string contentsubject;
    std::string violationbody;
#endif

    unsigned int banned_phrase_list;
    unsigned int exception_site_list;
    unsigned int exception_url_list;
    unsigned int banned_extension_list;
    unsigned int banned_mimetype_list;
    unsigned int banned_site_list;
    unsigned int banned_url_list;
    unsigned int grey_site_list;
    unsigned int grey_url_list;
    unsigned int banned_regexpurl_list;
    unsigned int exception_regexpurl_list;
    unsigned int banned_regexpheader_list;
    unsigned int content_regexp_list;
    unsigned int url_regexp_list;
    unsigned int sslsite_regexp_list;
    unsigned int header_regexp_list;
    unsigned int exception_extension_list;
    unsigned int exception_mimetype_list;
    unsigned int exception_file_site_list;
    unsigned int exception_file_url_list;
    unsigned int log_site_list;
    unsigned int log_url_list;
    unsigned int log_regexpurl_list;

    unsigned int referer_exception_site_list;
    unsigned int referer_exception_url_list;
    unsigned int embeded_referer_site_list;
    unsigned int embeded_referer_url_list;
#ifdef PRT_DNSAUTH
    unsigned int auth_exception_site_list;
    unsigned int auth_exception_url_list;
#endif
    unsigned int addheader_regexp_list;
    unsigned int banned_search_list;
    unsigned int search_regexp_list;
    unsigned int local_banned_search_list;
    unsigned int banned_search_overide_list;
    unsigned int local_exception_site_list;
    unsigned int local_exception_url_list;
    unsigned int local_banned_site_list;
    unsigned int local_banned_ssl_site_list;
    unsigned int local_grey_ssl_site_list;
    unsigned int local_banned_url_list;
    unsigned int local_grey_site_list;
    unsigned int local_grey_url_list;
    bool use_only_local_allow_lists;
    unsigned int banned_ssl_site_list;
    unsigned int grey_ssl_site_list;

    unsigned int no_check_cert_site_list;

    unsigned int url_redirect_regexp_list;
    std::deque<RegExp> url_redirect_regexp_list_comp;
    std::deque<String> url_redirect_regexp_list_rep;
    bool url_redirect_regexp_flag;
    bool allow_empty_host_certs;

    // regex match lists
    std::deque<RegExp> banned_regexpurl_list_comp;
    std::deque<String> banned_regexpurl_list_source;
    std::deque<unsigned int> banned_regexpurl_list_ref;
    std::deque<RegExp> exception_regexpurl_list_comp;
    std::deque<String> exception_regexpurl_list_source;
    std::deque<unsigned int> exception_regexpurl_list_ref;
    std::deque<RegExp> banned_regexpheader_list_comp;
    std::deque<String> banned_regexpheader_list_source;
    std::deque<unsigned int> banned_regexpheader_list_ref;
    std::deque<RegExp> log_regexpurl_list_comp;
    std::deque<String> log_regexpurl_list_source;
    std::deque<unsigned int> log_regexpurl_list_ref;

    // regex search & replace lists
    std::deque<RegExp> content_regexp_list_comp;
    std::deque<String> content_regexp_list_rep;
    std::deque<RegExp> url_regexp_list_comp;
    std::deque<String> url_regexp_list_rep;
    std::deque<RegExp> sslsite_regexp_list_comp;
    std::deque<String> sslsite_regexp_list_rep;
    std::deque<RegExp> header_regexp_list_comp;
    std::deque<String> header_regexp_list_rep;
    std::deque<RegExp> search_regexp_list_comp;
    std::deque<String> search_regexp_list_rep;
    std::deque<RegExp> addheader_regexp_list_comp;
    std::deque<String> addheader_regexp_list_rep;

    // precompiled reg exps for speed
    RegExp pics1;
    RegExp pics2;
    RegExp isiphost;

    // access denied address & domain - if they override the defaults
    std::string access_denied_address;
    std::string sslaccess_denied_address;
    String access_denied_domain;
    String sslaccess_denied_domain;
    bool ssl_denied_rewrite;
    // search term blocking
    //unsigned int searchengine_regexp_list;
    unsigned int searchterm_list;
    bool searchterm_flag;
    //std::deque<RegExp> searchengine_regexp_list_comp;
    //std::deque<String> searchengine_regexp_list_source;
    //std::deque<unsigned int> searchengine_regexp_list_ref;
    //bool extractSearchTerms(String url, String &terms);

    FOptionContainer()
        : block_downloads(false), searchterm_flag(false), banned_page(NULL), ssl_mitm(false), only_mitm_ssl_grey(false), no_check_cert_site_flag(false), ssl_check_cert(false), mitm_check_cert(true), referer_exception_site_flag(false), referer_exception_url_flag(false), embeded_referer_site_flag(false), embeded_referer_url_flag(false),
#ifdef PRT_DNSAUTH
        auth_exception_site_flag(false)
        , auth_exception_url_flag(false)
        ,
#endif
        addheader_regexp_flag(false)
        , banned_search_flag(false)
        , search_regexp_flag(false)
        , local_banned_search_flag(false)
        , banned_search_overide_flag(false)
        , local_exception_site_flag(false)
        , local_exception_url_flag(false)
        , local_banned_site_flag(false)
        , local_banned_url_flag(false)
        , local_grey_site_flag(false)
        , local_grey_url_flag(false)
        , enable_regex_grey(false)
        , enable_local_list(false)
        , enable_ssl_legacy_logic(false)
        , use_only_local_allow_lists(false)
        , banned_phrase_flag(false)
        , exception_site_flag(false)
        , exception_url_flag(false)
        , banned_extension_flag(false)
        , banned_mimetype_flag(false)
        , banned_site_flag(false)
        , banned_url_flag(false)
        , grey_site_flag(false)
        , grey_url_flag(false)
        , banned_regexpurl_flag(false)
        , exception_regexpurl_flag(false)
        , banned_regexpheader_flag(false)
        , content_regexp_flag(false)
        , url_regexp_flag(false)
        , sslsite_regexp_flag(false)
        , header_regexp_flag(false)
        , url_redirect_regexp_flag(false)
        , exception_extension_flag(false)
        , exception_mimetype_flag(false)
        , exception_file_site_flag(false)
        , exception_file_url_flag(false)
        , log_site_flag(false)
        , log_url_flag(false)
        , log_regexpurl_flag(false)
        , ssl_denied_rewrite(false)
        , allow_empty_host_certs(false)
        , pics_icra_nuditymalegraphic(0)
        , pics_icra_nudityfemalegraphic(0)
        , pics_icra_nuditytopless(0)
        , pics_icra_nuditybottoms(0)
        , pics_icra_nuditysexualacts(0)
        , pics_icra_nudityobscuredsexualacts(0)
        , pics_icra_nuditysexualtouching(0)
        , pics_icra_nuditykissing(0)
        , pics_icra_nudityartistic(0)
        , pics_icra_nudityeducational(0)
        , pics_icra_nuditymedical(0)
        , pics_icra_drugstobacco(0)
        , pics_icra_drugsalcohol(0)
        , pics_icra_drugsuse(0)
        , pics_icra_gambling(0)
        , pics_icra_weaponuse(0)
        , pics_icra_intolerance(0)
        , pics_icra_badexample(0)
        , pics_icra_pgmaterial(0)
        , pics_icra_violencerape(0)
        , pics_icra_violencetohumans(0)
        , pics_icra_violencetoanimals(0)
        , pics_icra_violencetofantasy(0)
        , pics_icra_violencekillinghumans(0)
        , pics_icra_violencekillinganimals(0)
        , pics_icra_violencekillingfantasy(0){};
    ~FOptionContainer();
    bool read(const char *filename);
    void reset();
    void resetJustListData();

    bool isOurWebserver(String url);
    char *inAddheaderList(String &words, unsigned int list);
    char *inBannedSearchList(String words);
    char *inSearchList(String &words, unsigned int list);
    char *inLocalBannedSearchList(String words);
    bool inBannedSearchOverideList(String words);
    char *inLocalBannedSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    char *inLocalBannedSSLSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    char *inLocalBannedURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inLocalGreySiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inLocalGreySSLSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inLocalGreyURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inLocalExceptionSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inLocalExceptionURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    char *inBannedSSLSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inGreySSLSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inNoCheckCertSiteList(String url, bool ip = false);
#ifdef PRT_DNSAUTH
    bool inAuthExceptionSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inAuthExceptionURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
#endif
    bool inRefererExceptionLists(String url);
    bool inEmbededRefererLists(String url);
    char *inBannedSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    char *inBannedURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inGreySiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inGreyURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inExceptionSiteList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inExceptionURLList(String url, bool doblanket = false, bool ip = false, bool ssl = false);
    bool inExceptionFileSiteList(String url);
    int inBannedRegExpURLList(String url);
    int inExceptionRegExpURLList(String url);
    int inBannedRegExpHeaderList(std::deque<String> &header);
    char *inExtensionList(unsigned int list, String url);
    bool isIPHostname(String url);
    bool addheader_regexp_flag; // public as used by HTTPHeader.cpp
    bool search_regexp_flag;    // public as used by HTTPHeader.cpp
    bool sslsite_regexp_flag;   // public as used by HTTPHeader.cpp

    // log-only lists - return category
    const char *inLogURLList(String url);
    const char *inLogSiteList(String url);
    const char *inLogRegExpURLList(String url);

    // get HTML template for this group
    HTMLTemplate *getHTMLTemplate();
    std::deque<std::string> text_mime;

    private:
    // HTML template - if it overrides the default
    HTMLTemplate *banned_page;

    bool banned_phrase_flag;
    bool exception_site_flag;
    bool exception_url_flag;
    bool banned_extension_flag;
    bool banned_mimetype_flag;
    bool banned_site_flag;
    bool banned_url_flag;
    bool grey_site_flag;
    bool grey_url_flag;
    bool banned_regexpurl_flag;
    bool exception_regexpurl_flag;
    bool banned_regexpheader_flag;
    bool content_regexp_flag;
    bool url_regexp_flag;
    bool header_regexp_flag;
    bool exception_extension_flag;
    bool exception_mimetype_flag;
    bool exception_file_site_flag;
    bool exception_file_url_flag;
    bool log_site_flag;
    bool log_url_flag;
    bool log_regexpurl_flag;
    bool referer_exception_site_flag;
    bool referer_exception_url_flag;
    bool embeded_referer_site_flag;
    bool embeded_referer_url_flag;
#ifdef PRT_DNSAUTH
    bool auth_exception_site_flag;
    bool auth_exception_url_flag;
#endif
    //	bool addheader_regexp_flag;  // moved to public as used by HTTPHeader.cpp
    bool banned_search_flag;
    //bool search_regexp_flag;  // moved to public as used by HTTPHeader.cpp
    bool local_banned_search_flag;
    bool banned_search_overide_flag;
    bool local_exception_site_flag;
    bool local_exception_url_flag;
    bool local_banned_site_flag;
    bool local_banned_url_flag;
    bool local_grey_site_flag;
    bool local_grey_url_flag;
    bool local_grey_ssl_site_flag;
    bool local_banned_ssl_site_flag;
    bool grey_ssl_site_flag;
    bool banned_ssl_site_flag;
    bool no_check_cert_site_flag;

    // search term blocking
    //bool searchengine_regexp_flag;

    std::deque<int> banned_phrase_list_index;

    std::deque<std::string> conffile;

    bool precompileregexps();
    // Not sure if this next line is needed - PIP
    bool readbplfil(const char *banned, const char *exception, const char *weighted);
    bool readFile(const char *filename, unsigned int *whichlist, bool sortsw, bool cache, const char *listname);
    bool readRegExMatchFile(const char *filename, const char *listname, unsigned int &listref,
        std::deque<RegExp> &list_comp, std::deque<String> &list_source, std::deque<unsigned int> &list_ref);
    bool compileRegExMatchFile(unsigned int list, std::deque<RegExp> &list_comp,
        std::deque<String> &list_source, std::deque<unsigned int> &list_ref);
    bool readRegExReplacementFile(const char *filename, const char *listname, unsigned int &listid,
        std::deque<String> &list_rep, std::deque<RegExp> &list_comp);

    int findoptionI(const char *option);
    std::string findoptionS(const char *option);
    bool realitycheck(long int l, long int minl, long int maxl, const char *emessage);
    int inRegExpURLList(String &url, std::deque<RegExp> &list_comp, std::deque<unsigned int> &list_ref, unsigned int list);

    char *inURLList(String &url, unsigned int list, bool doblanket = false, bool ip = false, bool ssl = false);
    char *inSiteList(String &url, unsigned int list, bool doblanket = false, bool ip = false, bool ssl = false);

    char *testBlanketBlock(unsigned int list, bool ip, bool ssl);
};

#endif
