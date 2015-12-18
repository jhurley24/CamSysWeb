<?php
/**
 * @file
 * contact_section.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function contact_section_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact_block';
  $context->description = '';
  $context->tag = 'contact';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'content',
          'weight' => '-32',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '1',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-location_list-block' => array(
          'module' => 'views',
          'delta' => 'location_list-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('contact');
  $export['contact_block'] = $context;

  return $export;
}
