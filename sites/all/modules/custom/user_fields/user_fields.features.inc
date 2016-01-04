<?php
/**
 * @file
 * user_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function user_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function user_fields_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
