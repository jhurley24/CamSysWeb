<?php
/**
 * @file
 * user_fields.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function user_fields_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|token';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'token';
  $ds_fieldsetting->settings = array(
    'field_credential' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_user_photo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['user|user|token'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function user_fields_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|token';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'token';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_user_photo',
      ),
      'right' => array(
        1 => 'group_name_credentials',
        2 => 'field_first_name',
        3 => 'field_last_name',
        4 => 'field_credential',
        5 => 'field_position',
        6 => 'field_phone',
        7 => 'field_bio',
      ),
    ),
    'fields' => array(
      'field_user_photo' => 'left',
      'group_name_credentials' => 'right',
      'field_first_name' => 'right',
      'field_last_name' => 'right',
      'field_credential' => 'right',
      'field_position' => 'right',
      'field_phone' => 'right',
      'field_bio' => 'right',
    ),
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
  );
  $export['user|user|token'] = $ds_layout;

  return $export;
}
