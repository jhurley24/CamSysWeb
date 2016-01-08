<?php
/**
 * @file
 * publications.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function publications_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_type|node|publication|default';
  $field_group->group_name = 'group_date_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and Publication Type',
    'weight' => '0',
    'children' => array(
      0 => 'field_publication_date',
      1 => 'field_publication_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and Publication Type',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-date-type field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_type|node|publication|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_type|node|publication|teaser';
  $field_group->group_name = 'group_date_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and Publication Type',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication_date',
      1 => 'field_publication_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and Publication Type',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-date-type field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_type|node|publication|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Date and Publication Type');

  return $field_groups;
}
