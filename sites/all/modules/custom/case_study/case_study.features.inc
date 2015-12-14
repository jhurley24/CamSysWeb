<?php
/**
 * @file
 * case_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function case_study_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function case_study_node_info() {
  $items = array(
    'case_study' => array(
      'name' => t('Case Studies'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
