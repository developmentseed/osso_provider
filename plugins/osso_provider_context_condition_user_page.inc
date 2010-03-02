<?php

class osso_provider_context_condition_user_page extends context_condition {
  function condition_values() {
    return array(
      'current' => t('Current user'),
      'other' => t('Other users'),
    );
  }

  function execute() {
    if (arg(0) === 'user' && is_numeric(arg(1)) && !arg(2)) {
      global $user;
      $uid = arg(1);
      if ($uid === $user->uid) {
        foreach ($this->get_contexts('current') as $context) {
          $this->condition_met($context, 'current');
        }
      }
      else {
        foreach ($this->get_contexts('other') as $context) {
          $this->condition_met($context, 'other');
        }
      }
    }
  }
}
