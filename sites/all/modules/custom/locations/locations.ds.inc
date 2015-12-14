<?php
/**
 * @file
 * locations.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function locations_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|location|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'location';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_telephone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'tel',
        ),
      ),
    ),
    'field_fax_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'fax',
        ),
      ),
    ),
  );
  $export['node|location|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|location|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'location';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'More >',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_telephone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'tel',
        ),
      ),
    ),
    'field_fax_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'tel',
        ),
      ),
    ),
  );
  $export['node|location|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function locations_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|location|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'location';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
      ),
      'middle' => array(
        1 => 'field_location_address',
        2 => 'field_location_image',
      ),
      'right' => array(
        3 => 'field_telephone_number',
        4 => 'field_fax_number',
        5 => 'field_location_email',
      ),
      'footer' => array(
        6 => 'field_geolocation',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_location_address' => 'middle',
      'field_location_image' => 'middle',
      'field_telephone_number' => 'right',
      'field_fax_number' => 'right',
      'field_location_email' => 'right',
      'field_geolocation' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|location|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|location|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'location';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_location_address',
        2 => 'field_telephone_number',
        3 => 'field_fax_number',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_location_address' => 'ds_content',
      'field_telephone_number' => 'ds_content',
      'field_fax_number' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|location|teaser'] = $ds_layout;

  return $export;
}
