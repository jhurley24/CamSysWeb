<?php
/**
 * @file
 * careers_misc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function careers_misc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function careers_misc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
