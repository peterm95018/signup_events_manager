<?php
// $Id$

/**
 * @file
 * Administrative list of all users signed up for a given node.
 */
 
/**
 * Implementation of hook_views_data().
 */
function signup_events_manager_views_data() {
  // Define the base group of the signup table.  Fields that don't
  // have a group defined will go into this field by default.
  $data['signup_events_manager']['table']['group'] = t('Signup Events Manager');

  $data['signup_events_log']['table']['join'] = array(
  'node' => array(
    'left_field' => 'nid',
    'field' => 'nid',
  ),
  );

  // Define base group for signup_log table.
  $data['signup_events_log']['table']['group'] = t('Signup Events Manager');

  // Advertise this table as a possible base table so that we can have
  // "Signup" views. This is essential for Views Bulk Operations to work,
  // since we need operations on the signups themselves, not the users or
  // nodes they point to.  With proper use of relationships, we can get
  // everything on signup views we'd want from either node or user views.
  $data['signup_events_log']['table']['base'] = array(
  'field' => 'id',
  'title' => t('Signup Events Manager'),
  'help' => t('A signup represents a relationship between a user and a node.'),
  );

  $data['signup_events_log']['table']['join'] = array(
  'node' => array(
  'left_field' => 'nid',
  'field' => 'nid',
  ),
  'users' => array(
  'left_field' => 'uid',
  'field' => 'uid',
  ),
  'signup_log' => array(
  'left_field' => 'sid',
  'field' => 'sid'
  ),
  );

  $data['signup_events_log']['First'] = array(
  'title' => t('First name'),
  'help' => t('The signup First entry'),
  // Information for displaying the field
  'field' => array(
  'handler' => 'views_handler_field',
  'click sortable' => TRUE,
  ),
  // Information for accepting sid as a filter
  'filter' => array(
  'label' => t('Signup first entry'),
  'handler' => 'views_handler_filter',
  ),
  // Information for sorting on sid
  'sort' => array(
  'handler' => 'views_handler_sort',
  'help' => t('Sort by First name.'),
  )
  );

  $data['signup_events_log']['Last'] = array(
  'title' => t('Last name'),
  'help' => t('The signup Last entry'),
  // Information for displaying the field
  'field' => array(
  'handler' => 'views_handler_field',
  'click sortable' => TRUE,
  ),
  // Information for accepting sid as a filter
  'filter' => array(
  'label' => t('Signup Last entry'),
  'handler' => 'views_handler_filter',
  ),
  // Information for sorting on sid
  'sort' => array(
  'handler' => 'views_handler_sort',
  'help' => t('Sort by Last name.'),
  )
  );

  $data['signup_events_log']['Unit'] = array(
  'title' => t('Unit name'),
  'help' => t('The signup Unit entry'),
  // Information for displaying the field
  'field' => array(
  'handler' => 'views_handler_field',
  'click sortable' => TRUE,
  ),
  // Information for accepting sid as a filter
  'filter' => array(
  'label' => t('Signup unit entry'),
  'handler' => 'views_handler_filter',
  ),
  // Information for sorting on sid
  'sort' => array(
  'handler' => 'views_handler_sort',
  'help' => t('Sort by unit name.'),
  )
  );

  $data['signup_events_log']['Phone'] = array(
  'title' => t('Phone number'),
  'help' => t('The signup Phone entry'),
  // Information for displaying the field
  'field' => array(
  'handler' => 'views_handler_field',
  'click sortable' => TRUE,
  ),
  // Information for accepting sid as a filter
  'filter' => array(
  'label' => t('Signup phone entry'),
  'handler' => 'views_handler_filter',
  ),
  // Information for sorting on sid
  'sort' => array(
  'handler' => 'views_handler_sort',
  'help' => t('Sort by Phone number.'),
  )
  );


  $data['signup_events_log']['nid'] = array(
  'title' => t('Nid'),
  'help' => t('The node ID of the node.'), // The help that appears on the UI,
  // Information for displaying the nid
  'field' => array(
  'handler' => 'views_handler_field_node',
  'click sortable' => TRUE,
  ),
  // Information for accepting a nid as an argument
  'argument' => array(
  'handler' => 'views_handler_argument_node_nid',
  'name field' => 'title', // the field to display in the summary.
  'numeric' => TRUE,
  'validate type' => 'nid',
  ),
  // Information for accepting a nid as a filter
  'filter' => array(
  'handler' => 'views_handler_filter_numeric',
  ),
  // Information for sorting on a nid.
  'sort' => array(
  'handler' => 'views_handler_sort',
  ),
  );

  return $data;  
}