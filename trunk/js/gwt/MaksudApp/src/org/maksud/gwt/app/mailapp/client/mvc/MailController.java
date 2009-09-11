/*
 * Ext GWT - Ext for GWT
 * Copyright(c) 2007-2009, Ext JS, LLC.
 * licensing@extjs.com
 * 
 * http://extjs.com/license
 */
package org.maksud.gwt.app.mailapp.client.mvc;

import java.util.List;

import org.maksud.gwt.app.common.client.gxtmodel.Folder;
import org.maksud.gwt.app.common.client.gxtmodel.MailItem;
import org.maksud.gwt.app.mailapp.client.AppEvents;
import org.maksud.gwt.app.mailapp.client.MailApp;
import org.maksud.gwt.app.mailapp.client.MailServiceAsync;

import com.extjs.gxt.ui.client.Registry;
import com.extjs.gxt.ui.client.event.EventType;
import com.extjs.gxt.ui.client.mvc.AppEvent;
import com.extjs.gxt.ui.client.mvc.Controller;
import com.extjs.gxt.ui.client.mvc.Dispatcher;
import com.google.gwt.user.client.rpc.AsyncCallback;

public class MailController extends Controller {

  private MailServiceAsync service;
  private MailFolderView folderView;
  private MailView mailView;

  public MailController() {
    registerEventTypes(AppEvents.Init);
    registerEventTypes(AppEvents.NavMail);
    registerEventTypes(AppEvents.ViewMailItems);
    registerEventTypes(AppEvents.ViewMailItem);
  }

  @Override
  public void handleEvent(AppEvent event) {
    EventType type = event.getType();
    if (type == AppEvents.Init) {
      forwardToView(folderView, event);
    } else if (type == AppEvents.NavMail) {
      forwardToView(folderView, event);
      forwardToView(mailView, event);
    } else if (type == AppEvents.ViewMailItems) {
      onViewMailItems(event);
    } else if (type == AppEvents.ViewMailItem) {
      forwardToView(mailView, event);
    }
  }

  private void onViewMailItems(final AppEvent event) {
    final Folder f = event.getData();
    if (f != null) {
      service.getMailItems(f, new AsyncCallback<List<MailItem>>() {
        public void onSuccess(List<MailItem> result) {
          AppEvent ae = new AppEvent(event.getType(), result);
          ae.setData("folder", f);
          forwardToView(mailView, ae);
        }

        public void onFailure(Throwable caught) {
          Dispatcher.forwardEvent(AppEvents.Error, caught);
        }
      });
    }

  }

  public void initialize() {
    service = (MailServiceAsync) Registry.get(MailApp.SERVICE);

    folderView = new MailFolderView(this);
    mailView = new MailView(this);
  }

}
