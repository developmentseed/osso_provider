<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function osso_provider_context_default_contexts() {
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
      ),
      'layout' => 'default',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OSSO Provider');

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
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('OSSO Provider');

  $export['osso_provider_user'] = $context;
  return $export;
}
