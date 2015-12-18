<?php
/**
 * @file
 * insights.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function insights_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'insights_search';
  $context->description = '';
  $context->tag = 'insights';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'insights' => 'insights',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search_posts-page' => array(
          'module' => 'views',
          'delta' => '-exp-search_posts-page',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('insights');
  $export['insights_search'] = $context;

  return $export;
}