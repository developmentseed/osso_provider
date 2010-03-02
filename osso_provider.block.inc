<?php

/**
 * Generate hub bar.
 */
function osso_provider_block_site_network() {
  global $user;

  // Generate links to relying parties.
  $links = array();
  $links['provider'] = array(
    'title' => variable_get('site_name', 'Drupal'),
    'href' => '<front>',
  );
  $i = 0;
  foreach (openid_provider_sso_relying_parties() as $rp) {
    $links["relying {$i}"] = array(
      'title' => $rp['name'],
      'href' => $rp['realm'],
    );
    $i++;
  }
  $output = theme('links', $links, array('class' => 'links site-links'));

  // Generate user links.
  $links = array();
  if ($user->uid) {
    $links['username'] = array(
      'title' => t('Hello @user', array('@user' => $user->name)),
      'href' => 'user/'. $user->uid,
    );
    $links['logout'] = array(
      'title' => t('Log out'),
      'href' => 'logout',
    );
  }
  else {
    $links['login'] = array(
      'title' => t('Log in / Sign up'),
      'href' => 'user/login',
    );
  }
  $output .= theme('links', $links, array('class' => 'links user-links'));
  return array('content' => $output);
}

/**
 * Login page message.
 */
function osso_provider_block_login_message() {
  $output = '<div class="sso-message">';
  if (isset($_SESSION['openid_provider']['request']['openid.realm']) && $relying_party = openid_provider_sso_relying_party($_SESSION['openid_provider']['request']['openid.realm'])) {
    drupal_set_title(t('Login to @relying_party', array('@relying_party' => $relying_party['name'])));
    $output .= '<p>'. t('<strong>@relying_party</strong> is part of <strong>@site_name</strong>. ', array('@site_name' => variable_get('site_name', 'Drupal'), '@relying_party' => $relying_party['name'])) .'</p>';
  }
  $output .= '<p>'. t('An account on @site_name gives you easy access to a series of sites with a single username and password.', array('@site_name' => variable_get('site_name', 'Drupal'))) .'</p>';
  $output .= '</div>';
  return array(
    'subject' => t('User login'),
    'content' => $output,
  );
}

/**
 * Welcome page message.
 */
function osso_provider_block_welcome_message() {
  $relying_parties = array();

  foreach (variable_get('openid_provider_sso_rps', array()) as $rp) {
    $relying_parties[] = $rp['name'];
  }

  $examples = array_pop($relying_parties);
  if ($relying_parties = implode(', ', $relying_parties)) {
    $examples = $relying_parties .' or '. $examples;
  }

  $content = t('<p>@site_name is your key to a host of sites.</p>',  array('@site_name' => variable_get('site_name', 'Drupal')));
  $content .= t('<p>Create an account once, and gain easy access with one username and password to sites like !examples.</p>',  array('!examples' => $examples));

  return array(
    'title' => t('Welcome'),
    'content' => $content,
  );
}
