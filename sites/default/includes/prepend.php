<?php

// Chef-populated constants
define('PANTHEON_INFRASTRUCTURE_ENVIRONMENT', 'live');
define('PANTHEON_SITE', '08fa6caf-abad-4aed-b212-91b5bfe7abc7');
define('PANTHEON_ENVIRONMENT', 'dev');
define('PANTHEON_BINDING', '6fb8f700d40e44b5b141a021fde5a3ac');
define('PANTHEON_BINDING_UID_NUMBER', '20293');

define('PANTHEON_DATABASE_HOST', '10.223.192.211');
define('PANTHEON_DATABASE_PORT', '11857');
define('PANTHEON_DATABASE_USERNAME', '');
define('PANTHEON_DATABASE_PASSWORD', '');
define('PANTHEON_DATABASE_DATABASE', '');
define('PANTHEON_DATABASE_BINDING', '6ec18e519df041d9a56693e7494920be');

define('PANTHEON_REDIS_HOST', '10.223.224.34');
define('PANTHEON_REDIS_PORT', '12742');
define('PANTHEON_REDIS_PASSWORD', 'dbecd9b5f9f14526a44768897105bd26');
define('PANTHEON_VALHALLA_HOST', 'valhalla2.cluster.panth.io');



// System paths
putenv('PATH=/usr/local/bin:/bin:/usr/bin:/srv/bin');

// Legacy Drupal Settings Block
$_SERVER['PRESSFLOW_SETTINGS'] = '{"conf":{"pressflow_smart_start":true,"pantheon_binding":"6fb8f700d40e44b5b141a021fde5a3ac","pantheon_site_uuid":"08fa6caf-abad-4aed-b212-91b5bfe7abc7","pantheon_environment":"dev","pantheon_tier":"live","pantheon_index_host":"eefa56f7-767a-4a3b-b2b7-37c47a5bf087-private.panth.io","pantheon_index_port":449,"redis_client_host":"10.223.224.34","redis_client_port":12742,"redis_client_password":"dbecd9b5f9f14526a44768897105bd26","file_public_path":"sites/default/files","file_private_path":"sites/default/files/private","file_directory_path":"sites/default/files","file_temporary_path":"/srv/bindings/6fb8f700d40e44b5b141a021fde5a3ac/tmp","file_directory_temp":"/srv/bindings/6fb8f700d40e44b5b141a021fde5a3ac/tmp","css_gzip_compression":false,"js_gzip_compression":false,"page_compression":false},"databases":{"default":{"default":{"host":"10.223.192.211","port":11857,"username":"pantheon","password":"a50a9cbbeafd4577ace767133addc449","database":"pantheon","driver":"mysql"}}},"drupal_hash_salt":"6c771bdf73ebc899f526e629ab7563802f682fab22045bbcd18e3e33bdd076db","config_directory_name":"config"}';

// Modern Dotenv.php settings loading
include_once('/srv/includes/Dotenv.php');
Dotenv::load('/srv/bindings/'. PANTHEON_BINDING);

/**
 * These $_SERVER variables are often used for redirects in code that is read
 * directly (e.g. settings.php) so we can't have them visible to the CLI lest
 * CLI processes might hit a redirect (e.g. header() and exit()) and die.
 *
 * CLI tools are encouraged to use getenv() or $_ENV going forward to read
 * environment configuration.
 */
if (isset($_SERVER['GATEWAY_INTERFACE'])) {
  $_SERVER['PANTHEON_ENVIRONMENT'] = 'dev';
  $_SERVER['PANTHEON_SITE'] = '08fa6caf-abad-4aed-b212-91b5bfe7abc7';
}
else {
  unset($_SERVER['PANTHEON_ENVIRONMENT']);
  unset($_SERVER['PANTHEON_SITE']);
}

require '/srv/includes/pantheon.php';
initialize_pantheon();
