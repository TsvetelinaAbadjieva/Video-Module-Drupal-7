<?php

function set_brightcove_settings(){
  $form = [];
  $form['brightcove_settings']['fieldset_client'] = array(
    '#type' => 'fieldset',
    '#title'=> t('Client Brightcove credentials')
  );

  $form['brightcove_settings']['fieldset_client']['account_id'] = array(
    '#title' => t('Type Your Brightcove provided Account Id'),
    '#type'  => 'textfield',
    '#default_value' => check_plain(variable_get('account_id', '')) ,
    '#required' => TRUE,
    '#weight' => -5,
    '#maxlength' => 127,
    '#minlength' => 3,
  );
  $form['brightcove_settings']['fieldset_client']['client_api_id'] = array(
    '#title' => t('Type Your Brightcove provided Api Client Id'),
    '#type'  => 'textfield',
    '#default_value' => check_plain(variable_get('client_api_id', '')),
    '#required' => TRUE,
    '#weight' => -5,
    '#maxlength' => 127,
    '#minlength' => 3,
  );
  $form['brightcove_settings']['fieldset_client']['secret_key'] = array(
    '#title' => t('Type Your Brightcove provided Secret key'),
    '#type'  => 'textfield',
    '#default_value' => check_plain(variable_get('secret_key', '')),
    '#required' => TRUE,
    '#weight' => -5,
    '#maxlength' => 127,
    '#minlength' => 3,
  );
  $form['brightcove_settings']['fieldset_iframe'] = array(
    '#type' => 'fieldset',
    '#title'=> t('Iframe dimension specification')
  );
  $form['brightcove_settings']['fieldset_iframe']['iframe_width'] = array(
    '#title' => t('Select prefered Iframe width'),
    '#type'  => 'textfield',
    '#default_value' => check_plain(variable_get('iframe_width', 100)),
    '#required' => TRUE,
    '#weight' => -5,
    '#number' => 127,
    '#minvalue'=> 100
  );
  $form['brightcove_settings']['fieldset_iframe']['iframe_height'] = array(
    '#title' => t('Select prefered Iframe Height'),
    '#type'  => 'textfield',
    '#default_value' => check_plain(variable_get('iframe_height', 100)),
    '#required' => TRUE,
    '#weight' => -5,
    '#number' => 127,
    '#minvalue'=> 100
  );

  $form['#validate'] [] = 'set_brightcove_settings_validate';

  return system_settings_form($form);
}

function set_brightcove_settings_validate(&$form, &$form_state) {

  $account_id = check_plain($form_state['values']['account_id']);
  $secret_key = check_plain($form_state['values']['secret_key']);
  $client_api_id = check_plain($form_state['values']['client_api_id']);
  $width = check_plain($form_state['values']['iframe_width']);
  $height = check_plain($form_state['values']['iframe_height']);


  if (strlen($account_id) == 0 || strlen($account_id) < 3) {
    form_set_error('account_id', t('Field %name must not be less than 3 symbols.', array('%name'=> 'Account Id')));
  }
  if(strlen($account_id) > 127){
    form_set_error('account_id', t('Field has too much symbols.'));
  }
  if (strlen($secret_key) == 0 || strlen($secret_key) < 3) {
    form_set_error('secret_key', t('Field  %name must not be less than 3 symbols.', array('%name'=> 'Secret key')));
  }
  if(strlen($secret_key) > 127){
    form_set_error('secret_key', t('Field has too much symbols.'));
  }
  if (strlen($client_api_id) == 0 || strlen($client_api_id) < 3) {
    form_set_error('secret_key', t('Field  %name must not be less than 3 symbols.', array('%name'=> 'Client API Id')));
  }
  if(strlen(client_api_id) > 127){
    form_set_error('secret_key', t('Field has too much symbols.'));
  }
  if ($width !== '' && (!is_numeric($width) || intval($width) != $width || $width <= 0)) {
    form_set_error('iframe_width', t('%name must be a positive integer.', array('%name' => 'Iframe width')));
  }
  if ($height !== '' && (!is_numeric($height) || intval($height) != $height || $height <= 0)) {
    form_set_error('iframe_heigh', t('%name must be a positive integer.', array('%name' => 'Iframe Height')));
  }
}
