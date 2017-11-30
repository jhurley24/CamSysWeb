<?php
/**
 * @file
 * landing_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function landing_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'landing_pages';
  $context->description = '';
  $context->tag = 'Landing';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'landing_page' => 'landing_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~careers' => '~careers',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recent_posts-block_3' => array(
          'module' => 'views',
          'delta' => 'recent_posts-block_3',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing');
  $export['landing_pages'] = $context;

  return $export;
}
