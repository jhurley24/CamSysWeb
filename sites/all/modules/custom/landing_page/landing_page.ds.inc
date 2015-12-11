<?php
/**
 * @file
 * landing_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function landing_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|landing_page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'landing_page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|landing_page|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function landing_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|landing_page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'landing_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'field_landing_page_image',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'field_landing_page_image' => 'right',
    ),
  );
  $export['node|landing_page|default'] = $ds_layout;

  return $export;
}
