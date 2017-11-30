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
        'global_filter-global_filter_1' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_1',
          'region' => 'content',
          'weight' => '-9',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_results';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'search_results:page' => 'search_results:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'global_filter-global_filter_1' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'views-search_results-block_3' => array(
          'module' => 'views',
          'delta' => 'search_results-block_3',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-search_results-block_1' => array(
          'module' => 'views',
          'delta' => 'search_results-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-search_results-block_2' => array(
          'module' => 'views',
          'delta' => 'search_results-block_2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['search_results'] = $context;

  return $export;
}
