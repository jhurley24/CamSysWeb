<?php
/**
 * @file
 * publications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function publications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function publications_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publications'),
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
