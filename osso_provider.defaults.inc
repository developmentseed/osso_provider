<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _osso_provider_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'osso_provider_login';
  $context->description = '';
  $context->tag = 'OSSO Provider';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'osso_provider-login_message' => array(
          'module' => 'osso_provider',
          'delta' => 'login_message',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-osso_provider_sites-block_1' => array(
          'module' => 'views',
          'delta' => 'osso_provider_sites-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
      'layout' => 'default',
    ),
  );
  $context->condition_mode = 1;

  $translatables['osso_provider_login'] = array(
    t('OSSO Provider'),
  );

  $export['osso_provider_login'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'osso_provider_user';
  $context->description = '';
  $context->tag = 'OSSO Provider';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'current' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-osso_provider_sites-block_2' => array(
          'module' => 'views',
          'delta' => 'osso_provider_sites-block_2',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $translatables['osso_provider_user'] = array(
    t('OSSO Provider'),
  );

  $export['osso_provider_user'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _osso_provider_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _osso_provider_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_email_verification';
  $strongarm->value = TRUE;

  $export['user_email_verification'] = $strongarm;
  return $export;
}
