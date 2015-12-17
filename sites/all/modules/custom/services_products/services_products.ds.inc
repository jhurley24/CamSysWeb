<?php
/**
 * @file
 * services_products.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function services_products_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|products_services|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'products_services';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'ps_contact' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|products_services|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|services|token';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'services';
  $ds_fieldsetting->view_mode = 'token';
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
    'more_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|services|token'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function services_products_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ps_contact';
  $ds_field->label = 'PS Contact';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|contact-block',
    'block_render' => '3',
  );
  $export['ps_contact'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function services_products_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|products_services|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'products_services';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_learn_more',
        2 => 'ps_contact',
      ),
      'right' => array(
        3 => 'field_case_study_reference',
        4 => 'field_publication_reference',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_learn_more' => 'left',
      'ps_contact' => 'left',
      'field_case_study_reference' => 'right',
      'field_publication_reference' => 'right',
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
    'layout_disable_css' => 0,
  );
  $export['node|products_services|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|services|token';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'services';
  $ds_layout->view_mode = 'token';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_teaser_text',
        2 => 'more_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_teaser_text' => 'ds_content',
      'more_link' => 'ds_content',
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
  $export['taxonomy_term|services|token'] = $ds_layout;

  return $export;
}
