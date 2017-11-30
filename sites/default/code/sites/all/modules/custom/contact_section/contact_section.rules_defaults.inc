<?php
/**
 * @file
 * contact_section.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function contact_section_default_rules_configuration() {
  $items = array();
  $items['rules_process_contact_submission'] = entity_import('rules_config', '{ "rules_process_contact_submission" : {
      "LABEL" : "Process Contact Submission",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "submission entered:\\r\\ntype: [entityform:type]\\r\\ncontact name:  [entityform:field_contact_name]\\r\\njob title: [entityform:field_job_title]" } }
      ]
    }
  }');
  return $items;
}
