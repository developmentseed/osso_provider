
# OSSO Provider for Open Atrium

OSSO = OpenID Simple Sign On

## Set up:

1. Install Open Atrium
2. Install drush and drush_make
3. Run rebuild.sh to build dependencies.
4. Install OSSO Provider module from admin/build/features page.
5. Go to admin/settings/openid-provider-sso and add trusted Relying Party sites
   (the assumption is that all of these sites have the [OSSO
   Relying](https://github.com/developmentseed/osso_relying) module installed.
6. Optionally, go to atrium/features and your site to "public access, open
   registration"
