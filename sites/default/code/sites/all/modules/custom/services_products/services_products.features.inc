<?php
/**
 * @file
 * services_products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function services_products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function services_products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function services_products_node_info() {
  $items = array(
    'products_services' => array(
      'name' => t('Products Services'),
      'base' => 'node_content',
      'description' => t('Products & Services content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
