<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function osso_provider_context_default_contexts() {
  module_load_include('inc', 'osso_provider', 'osso_provider.defaults');
  $args = func_get_args();
  return call_user_func_array('_osso_provider_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function osso_provider_ctools_plugin_api() {
  module_load_include('inc', 'osso_provider', 'osso_provider.defaults');
  $args = func_get_args();
  return call_user_func_array('_osso_provider_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function osso_provider_strongarm() {
  module_load_include('inc', 'osso_provider', 'osso_provider.defaults');
  $args = func_get_args();
  return call_user_func_array('_osso_provider_strongarm', $args);
}
