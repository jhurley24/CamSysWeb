<?php
/**
 * @file
 * user_fields.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function user_fields_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_dashboard';
  $context->description = '';
  $context->tag = 'user';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'user_dashboard:page' => 'user_dashboard:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_dashboard-block_3' => array(
          'module' => 'views',
          'delta' => 'user_dashboard-block_3',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-user_dashboard-block_2' => array(
          'module' => 'views',
          'delta' => 'user_dashboard-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('user');
  $export['user_dashboard'] = $context;

  return $export;
}
