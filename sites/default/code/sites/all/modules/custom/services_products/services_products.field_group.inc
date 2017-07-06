<?php
/**
 * @file
 * services_products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function services_products_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ps_contact|node|products_services|form';
  $field_group->group_name = 'group_ps_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'products_services';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PS Contact',
    'weight' => '38',
    'children' => array(
      0 => 'field_contact_reference',
      1 => 'field_learn_more',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ps-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ps_contact|node|products_services|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('PS Contact');

  return $field_groups;
}
