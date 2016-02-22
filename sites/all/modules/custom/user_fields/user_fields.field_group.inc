<?php
/**
 * @file
 * user_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function user_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_name_credentials|user|user|default';
  $field_group->group_name = 'group_name_credentials';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_credential',
      1 => 'field_first_name',
      2 => 'field_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'group-name-credentials field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_name_credentials|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_name_credentials|user|user|token';
  $field_group->group_name = 'group_name_credentials';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'token';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name & Credentials',
    'weight' => '1',
    'children' => array(
      0 => 'field_credential',
      1 => 'field_first_name',
      2 => 'field_last_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Name & Credentials',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-name-credentials field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_name_credentials|user|user|token'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Name & Credentials');

  return $field_groups;
}
