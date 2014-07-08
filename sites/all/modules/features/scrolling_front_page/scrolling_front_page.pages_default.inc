<?php
/**
 * @file
 * scrolling_front_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function scrolling_front_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'scrolling_front_page';
  $page->task = 'page';
  $page->admin_title = 'Scrolling front page';
  $page->admin_description = 'A front page with panel-rows that act as scrolling pages';
  $page->path = 'frontpage';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_scrolling_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'scrolling_front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'canvas-class',
        'column_class' => 'column-class',
        'row_class' => 'row-class',
        'region_class' => 'region-class',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0',
        'region_separation' => '0',
        'row_separation' => '0',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
          3 => 3,
          4 => 4,
        ),
        'parent' => 'canvas',
        'class' => 'column-1',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'full-width',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'About',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
          1 => 'upcoming_labs',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Menu',
        'width' => '25.051722039673848',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'upcoming_labs' => array(
        'type' => 'region',
        'title' => 'Upcoming labs',
        'width' => '74.94827796032615',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Projects',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'participants',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'participants' => array(
        'type' => 'region',
        'title' => 'Participants',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
          1 => 'footer_column_2',
          2 => 'footer_column_3',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer Column 1',
        'width' => '33.348045124114414',
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      'footer_column_2' => array(
        'type' => 'region',
        'title' => 'Footer Column 2',
        'width' => '33.018102795776855',
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      'footer_column_3' => array(
        'type' => 'region',
        'title' => 'Footer Column 3',
        'width' => '33.63385208010873',
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'test_left' => NULL,
      'test_right' => NULL,
      'center_' => NULL,
      'upcoming_labs' => NULL,
      'center__' => NULL,
      'participants' => NULL,
      'newsletter' => NULL,
      'footer' => NULL,
      'footer_column_2' => NULL,
      'footer_column_3' => NULL,
    ),
    'center' => array(
      'style' => 'sliding_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Choreographic Coding Labs';
  $display->uuid = '4f96690d-f2d3-4631-bcc5-22622aca0a12';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-99445121-bdac-468c-b343-2fc2cc3d0a1f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Slide',
      'title' => 'What are Choreographic Coding Labs?',
      'body' => 'The labs bring together the expertise of \'code savvy\' digital artists with dance and choreography in a focused setting. We believe that both fields share knowledge about movement and methods of structuring although from very different perspectives. Exploring these links and other connections through new forms and new methods of interaction has proven to be fruitful on many levels. New projects were started, new groups formed, new tools have been created …

The limited space and time of the labs asks for new ways to synchronise the collaboration between fast movements and often long running software development processes. We are eager to see how these problems are handled by the lab participants and what new systems might arise from it.

<a href="#" class="next-slide" title="next slide">&rarr; next</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'background_image' => array(
          'fid' => '11',
        ),
      ),
      'style' => 'sliding_region',
    );
    $pane->css = array(
      'css_id' => 'about',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99445121-bdac-468c-b343-2fc2cc3d0a1f';
    $display->content['new-99445121-bdac-468c-b343-2fc2cc3d0a1f'] = $pane;
    $display->panels['center'][0] = 'new-99445121-bdac-468c-b343-2fc2cc3d0a1f';
    $pane = new stdClass();
    $pane->pid = 'new-8350c33c-8cd1-4504-9fa5-ddfcaf9b9ffe';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Slide',
      'title' => 'How are they organised?',
      'body' => 'Each lab starts out by finding the right set of facilitators, often institutions, and a date and location. Once this is set a call is sent out asking for applications including some background and a project proposal. These help making sure that the mix of participants and what they bring to the lab is just right. A normal sized lab would be about 25 participants and should run for about 5 days. As there is no fee each lab needs funding which should be secured before the call is made. That funding should go to the people that spend time organising the lab and things that are required.

We consider the CCLs to be an open format and are happy to help you set up your own local CCL.

<a href="#" class="next-slide" title="next slide">&rarr; next</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'background_image' => array(
          'fid' => '15',
        ),
      ),
      'style' => 'sliding_region',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8350c33c-8cd1-4504-9fa5-ddfcaf9b9ffe';
    $display->content['new-8350c33c-8cd1-4504-9fa5-ddfcaf9b9ffe'] = $pane;
    $display->panels['center'][1] = 'new-8350c33c-8cd1-4504-9fa5-ddfcaf9b9ffe';
    $pane = new stdClass();
    $pane->pid = 'new-9673dcab-cece-4b5e-a7c6-be26277f769c';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Slide',
      'title' => 'Who is making the CCLs?',
      'body' => 'The "choreographic coding lab" format was invented 2013 as part of the Motion Bank research project of the Forsythe Company. Together with partners like the NODE forum for digital arts we, Motion Bank, will be organising and help organise more CCLs and additionally manage this website to promote the format.

As said it is an open format and we would love to see other people / organisations realise their own labs in the future. If that is you, please <a href="#contact">contact us</a>!

<a href="#" class="next-slide" title="next slide">&rarr; next</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'background_image' => array(
          'fid' => '3',
        ),
      ),
      'style' => 'sliding_region',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9673dcab-cece-4b5e-a7c6-be26277f769c';
    $display->content['new-9673dcab-cece-4b5e-a7c6-be26277f769c'] = $pane;
    $display->panels['center'][2] = 'new-9673dcab-cece-4b5e-a7c6-be26277f769c';
    $pane = new stdClass();
    $pane->pid = 'new-39c1c5e3-a283-4338-88f7-c1f3fba1f1c1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Slide',
      'title' => 'Stay informed!',
      'body' => 'Interested in participating in a future CCL or maybe want to organise one? Sign up to our <a href="#newsletter">newsletter</a> to stay informed.

<a href="#" class="next-slide" title="next slide">&rarr; next</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'background_image' => array(
          'fid' => '2',
        ),
      ),
      'style' => 'sliding_region',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '39c1c5e3-a283-4338-88f7-c1f3fba1f1c1';
    $display->content['new-39c1c5e3-a283-4338-88f7-c1f3fba1f1c1'] = $pane;
    $display->panels['center'][3] = 'new-39c1c5e3-a283-4338-88f7-c1f3fba1f1c1';
    $pane = new stdClass();
    $pane->pid = 'new-049840f4-98c2-4358-a1e6-a618ef2dc551';
    $pane->panel = 'center_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Upcoming Labs',
      'body' => '<ul>
<li><strong>2014</strong></li>
<li><a href="#lab-retune-2014">Retune</a></li>
<li><strong>2015</strong></li>
<li><a href="#lab-deakin-2015">Deakin MotionLab</a></li>
<li><a href="#lab-node-2015">NODE</a></li>
</ul>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'upcoming',
      'css_class' => 'menu sticky-in-region in-pane-nav',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '049840f4-98c2-4358-a1e6-a618ef2dc551';
    $display->content['new-049840f4-98c2-4358-a1e6-a618ef2dc551'] = $pane;
    $display->panels['center_'][0] = 'new-049840f4-98c2-4358-a1e6-a618ef2dc551';
    $pane = new stdClass();
    $pane->pid = 'new-fb5e28c8-313a-4347-be2b-4bcb000b8a55';
    $pane->panel = 'center__';
    $pane->type = 'views';
    $pane->subtype = 'projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => 'Projects',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'projects',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb5e28c8-313a-4347-be2b-4bcb000b8a55';
    $display->content['new-fb5e28c8-313a-4347-be2b-4bcb000b8a55'] = $pane;
    $display->panels['center__'][0] = 'new-fb5e28c8-313a-4347-be2b-4bcb000b8a55';
    $pane = new stdClass();
    $pane->pid = 'new-27509ef7-4062-45fd-9c9f-6e1e4538435f';
    $pane->panel = 'footer';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Newsletter',
      'body' => '<!-- Begin MailChimp Signup Form --><link href="//cdn-images.mailchimp.com/embedcode/classic-081711.css" rel="stylesheet" type="text/css">
<style type="text/css">
#mc_embed_signup { background:#fff; clear:left; }
#mc-embedded-subscribe-form, #mc_embed_signup form { padding: 0px; padding-right: 2em; }
#mc_embed_signup .mc-field-group .asterisk { top: 35px }
</style><div id="mc_embed_signup"><form action="//choreographiccoding.us8.list-manage.com/subscribe/post?u=5b3dec718900ad84210c545ac&amp;id=24abe7a566" method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate><div class="indicates-required"><span class="asterisk">*</span> indicates required</div><div class="mc-field-group"><label for="mce-EMAIL">Email Address  <span class="asterisk">*</span></label><input type="email" value="" name="EMAIL" class="required email" id="mce-EMAIL"></div><div class="mc-field-group"><label for="mce-FNAME">First Name </label><input type="text" value="" name="FNAME" class="" id="mce-FNAME"></div><div class="mc-field-group"><label for="mce-LNAME">Last Name </label><input type="text" value="" name="LNAME" class="" id="mce-LNAME"></div><div id="mce-responses" class="clear"><div class="response" id="mce-error-response" style="display:none"></div><div class="response" id="mce-success-response" style="display:none"></div></div><!-- real people should not fill this in and expect good things - do not remove this or risk form bot signups--><div style="position: absolute; left: -5000px;"><input type="text" name="b_5b3dec718900ad84210c545ac_24abe7a566" tabindex="-1" value=""></div><div class="clear"><input type="submit" value="Subscribe" name="subscribe" id="mc-embedded-subscribe" class="button"></div></form></div><script type=\'text/javascript\' src=\'//s3.amazonaws.com/downloads.mailchimp.com/js/mc-validate.js\'></script><script type=\'text/javascript\'>
(function($) {
window.fnames = new Array(); window.ftypes = new Array();fnames[0]=\'EMAIL\';ftypes[0]=\'email\';fnames[1]=\'FNAME\';ftypes[1]=\'text\';fnames[2]=\'LNAME\';ftypes[2]=\'text\';
}(jQuery));
var $mcj = jQuery.noConflict(true);
</script><!--End mc_embed_signup-->',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '27509ef7-4062-45fd-9c9f-6e1e4538435f';
    $display->content['new-27509ef7-4062-45fd-9c9f-6e1e4538435f'] = $pane;
    $display->panels['footer'][0] = 'new-27509ef7-4062-45fd-9c9f-6e1e4538435f';
    $pane = new stdClass();
    $pane->pid = 'new-dc3d7c89-6d28-46c6-8ab4-a7f9d962cf1d';
    $pane->panel = 'footer_column_2';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Contact',
      'body' => 'A project started at <a href="http://motionbank.org/" target="_blank">Motion Bank</a>

ccl<span class="at"/>motionbank<span class="dot"/>org

Gutleutstraße 8-12
c/o Florian Jenett
60329 Frankfurt am Main',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'contact',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dc3d7c89-6d28-46c6-8ab4-a7f9d962cf1d';
    $display->content['new-dc3d7c89-6d28-46c6-8ab4-a7f9d962cf1d'] = $pane;
    $display->panels['footer_column_2'][0] = 'new-dc3d7c89-6d28-46c6-8ab4-a7f9d962cf1d';
    $pane = new stdClass();
    $pane->pid = 'new-8395575e-4d7d-4fa1-a921-a71453e5adec';
    $pane->panel = 'footer_column_3';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Follow us',
      'body' => 'Please follow the Motion Bank <a href="https://twitter.com/motionbank" target="_blank">Twitter</a> or <a href="https://www.facebook.com/motionbank" target="_blank">Facebook</a> accounts.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8395575e-4d7d-4fa1-a921-a71453e5adec';
    $display->content['new-8395575e-4d7d-4fa1-a921-a71453e5adec'] = $pane;
    $display->panels['footer_column_3'][0] = 'new-8395575e-4d7d-4fa1-a921-a71453e5adec';
    $pane = new stdClass();
    $pane->pid = 'new-52868679-da9f-40a5-bdc8-abbef8691a57';
    $pane->panel = 'participants';
    $pane->type = 'views';
    $pane->subtype = 'participants';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => 'Participants',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'participants',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '52868679-da9f-40a5-bdc8-abbef8691a57';
    $display->content['new-52868679-da9f-40a5-bdc8-abbef8691a57'] = $pane;
    $display->panels['participants'][0] = 'new-52868679-da9f-40a5-bdc8-abbef8691a57';
    $pane = new stdClass();
    $pane->pid = 'new-0694acc2-00d0-417a-b0a9-4b7ec7a22f7d';
    $pane->panel = 'upcoming_labs';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Retune 2014',
      'body' => 'Next lab will happen between September 23rd and 27th as part of the <a href="http://retune.de/2014/" target="_blank">Retune conference</a> in Berlin.

The application process has started, use <a href="#lab-retune-2014-form">this form</a> to apply.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lab-retune-2014',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0694acc2-00d0-417a-b0a9-4b7ec7a22f7d';
    $display->content['new-0694acc2-00d0-417a-b0a9-4b7ec7a22f7d'] = $pane;
    $display->panels['upcoming_labs'][0] = 'new-0694acc2-00d0-417a-b0a9-4b7ec7a22f7d';
    $pane = new stdClass();
    $pane->pid = 'new-eb49172a-62c2-4614-81eb-7235e1af4b1b';
    $pane->panel = 'upcoming_labs';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Deakin MotionLab 2015',
      'body' => 'We are actively working on making this CCL happen in Melbourne in the first half of 2015. It is co-organised and will take place at the <a href="http://www.deakin.edu.au/motionlab/" target="_blank">MotionLab</a>. Please sign up for our <a href="#newsletter">newsletter</a> to stay informed about progress on this one.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lab-deakin-2015',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eb49172a-62c2-4614-81eb-7235e1af4b1b';
    $display->content['new-eb49172a-62c2-4614-81eb-7235e1af4b1b'] = $pane;
    $display->panels['upcoming_labs'][1] = 'new-eb49172a-62c2-4614-81eb-7235e1af4b1b';
    $pane = new stdClass();
    $pane->pid = 'new-ce3c8c99-7dc9-480e-a769-300abc8792df';
    $pane->panel = 'upcoming_labs';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'NODE Forum 2015',
      'body' => 'NODE is a co-organiser for our local CCLs so it is natural to host one at the NODE15 in Frankfurt end of April 2015. Please sign up for our <a href="#newsletter">newsletter</a> to be informed when application opens.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lab-node-2015',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ce3c8c99-7dc9-480e-a769-300abc8792df';
    $display->content['new-ce3c8c99-7dc9-480e-a769-300abc8792df'] = $pane;
    $display->panels['upcoming_labs'][2] = 'new-ce3c8c99-7dc9-480e-a769-300abc8792df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['scrolling_front_page'] = $page;

  return $pages;

}
