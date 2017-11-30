<?php
/**
 * @file
 * user_fields.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_fields_user_default_roles() {
  $roles = array();

  // Exported role: Leadership.
  $roles['Leadership'] = array(
    'name' => 'Leadership',
    'weight' => 4,
  );

  // Exported role: Staff.
  $roles['Staff'] = array(
    'name' => 'Staff',
    'weight' => 3,
  );

  return $roles;
}
