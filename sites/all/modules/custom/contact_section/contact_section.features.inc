<?php
/**
 * @file
 * contact_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function contact_section_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function contact_section_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function contact_section_default_entityform_type() {
  $items = array();
  $items['contact_form'] = entity_import('entityform_type', '{
    "type" : "contact_form",
    "label" : "Contact Form",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Send Message",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : 0, "3" : 0, "4" : 0, "5" : 0, "6" : 0, "7" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003ETo send us a message complete the form below. We will direct\\u0026nbsp;your inquiry to the appropriate staff member and provide you\\u0026nbsp;with a timely response.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cem\\u003EFields marked\\u0026nbsp;with a \\u003Cspan class=\\u0022form-required\\u0022\\u003E*\\u003C\\/span\\u003E are required.\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      },
      "current_type" : "contact_form",
      "enable_block" : 1
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/contact-form",
        "alias" : "contact-form",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/contact-form\\/confirm",
        "alias" : "contact\\/confirm",
        "language" : "und"
      }
    }
  }');
  return $items;
}
