<?php
/**
 * @file
 * content_moderation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function content_moderation_default_rules_configuration() {
  $items = array();
  $items['rules_content_create_notice'] = entity_import('rules_config', '{ "rules_content_create_notice" : {
      "LABEL" : "Content Create Notice",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "8" : "8" } },
            "subject" : "New content created",
            "message" : "New content has been created. Click below to view:\\r\\n\\r\\n\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:url]\\u003C\\/a\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_content_update_notice'] = entity_import('rules_config', '{ "rules_content_update_notice" : {
      "LABEL" : "Content Update Notice",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "NOT contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "8" : "8" } },
            "subject" : "Content Updated",
            "message" : "Content has been updated by [node:author]. Content can be viewed at:\\r\\n\\r\\n[node:url]"
          }
        }
      ]
    }
  }');
  return $items;
}
