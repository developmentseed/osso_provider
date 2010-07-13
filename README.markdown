
# OSSO Provider for Open Atrium

OSSO = OpenID Simple Sign On

## Set up:

1. Install Open Atrium
2. Install drush and drush_make
3. Run rebuild.sh to build dependencies.
4. Install OSSO Provider module from admin/build/features page.
5. Go to admin/settings/openid-provider-sso and add trusted Relying Party sites
   (the assumption is that all of these sites have the [OSSO
   Relying](https://github.com/developmentseed/osso_relying) feature installed.
6. Optionally, go to atrium/features and your site to "public access, open
   registration"

# Makefile

The following lines of makefile code will download this module's dependencies:

core = "6.x"

; Drupal queue
projects[drupal_queue][version] = "1.1"

; KeyAuth
projects[keyauth][type] = "module"
projects[keyauth][download][type] = "git"
projects[keyauth][download][url] = "git://github.com/developmentseed/keyauth.git"

; Open ID Provider
projects[openid_provider][type] = "module"
projects[openid_provider][download][type] = "cvs"
projects[openid_provider][download][module] = "contributions/modules/openid_provider"
projects[openid_provider][download][revision] = "DRUPAL-6--1:2010-03-02"
; http://drupal.org/node/621956#comment-2665966
projects[openid_provider][patch][] = "http://drupal.org/files/issues/621956-13_openid_provider_form.patch"
; http://drupal.org/node/810784
projects[openid_provider][patch][] = "http://drupal.org/files/issues/openid_provider-slow_association.patch"

; Open ID Provider SSO
projects[openid_provider_sso][type] = "module"
projects[openid_provider_sso][download][type] = "git"
projects[openid_provider_sso][download][url] = "git://github.com/developmentseed/openid_provider_sso.git"

; PuSH Hub
projects[push_hub][type] = "module"
projects[push_hub][download][type] = "git"
projects[push_hub][download][url] = "git://github.com/developmentseed/push_hub.git"

; XRDS Simple
projects[xrds_simple][version] = "1.0"

