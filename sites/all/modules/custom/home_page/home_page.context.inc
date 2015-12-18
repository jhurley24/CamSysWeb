<?php
/**
 * @file
 * home_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function home_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_blocks';
  $context->description = '';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-featured_case_studies-block_1' => array(
          'module' => 'views',
          'delta' => 'featured_case_studies-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-cs_sections-block' => array(
          'module' => 'views',
          'delta' => 'cs_sections-block',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-recent_posts-block_2' => array(
          'module' => 'views',
          'delta' => 'recent_posts-block_2',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('home');
  $export['home_blocks'] = $context;

  return $export;
}
