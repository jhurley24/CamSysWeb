<?php
/**
 * @file
 * user_fields.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_fields_default_rules_configuration() {
  $items = array();
  $items['rules_user_registration_actions'] = entity_import('rules_config', '{ "rules_user_registration_actions" : {
      "LABEL" : "User Registration Actions",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "9" : "9" } } } },
        { "mail" : {
            "to" : "csweb@camsys.com",
            "subject" : "New user registration",
            "message" : "A new user has registered on the site. View new user\\u0027s account information at: [account:url] (You must be logged in to view this page)",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
