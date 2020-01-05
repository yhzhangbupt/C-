package Entity;

import Entity.util.JsfUtil;
import Entity.util.PaginationHelper;

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;
import java.util.ResourceBundle;
import javax.ejb.EJB;
import javax.inject.Named;
import javax.enterprise.context.SessionScoped;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.convert.Converter;
import javax.faces.convert.FacesConverter;
import javax.faces.model.DataModel;
import javax.faces.model.ListDataModel;
import javax.faces.model.SelectItem;

@Named("guardProjController")
@SessionScoped
public class GuardProjController implements Serializable {

    private GuardProj current;
    private DataModel items = null;
    @EJB
    private Entity.GuardProjFacade ejbFacade;
    private PaginationHelper pagination;
    private int selectedItemIndex;
    
    private List<GuardProj> projectList;
    private List<String> guard_header;
    
    public void setProjectList(){
        
    }
    
    public List<GuardProj> getProjectList(){
        projectList = this.getFacade().findAll();
        return projectList;
    }
    
    public List<String> getGuardHeader() {
	return guard_header;
    }

    public void setGuardHeader(List<String> header) {
            this.guard_header = header;
    }
    
    
    private void initData(){
        guard_header = Arrays.asList(new String[]{"ID","名称","申请人","申请时间","门类","部类","url"});
    }
    

    public GuardProjController() {
        initData();
    }

    public GuardProj getSelected() {
        if (current == null) {
            current = new GuardProj();
            current.setGuardProjPK(new Entity.GuardProjPK());
            selectedItemIndex = -1;
        }
        return current;
    }

    private GuardProjFacade getFacade() {
        return ejbFacade;
    }

    public PaginationHelper getPagination() {
        if (pagination == null) {
            pagination = new PaginationHelper(10) {

                @Override
                public int getItemsCount() {
                    return getFacade().count();
                }

                @Override
                public DataModel createPageDataModel() {
                    return new ListDataModel(getFacade().findRange(new int[]{getPageFirstItem(), getPageFirstItem() + getPageSize()}));
                }
            };
        }
        return pagination;
    }

    public String prepareList() {
        recreateModel();
        return "List";
    }

    public String prepareView() {
        current = (GuardProj) getItems().getRowData();
        selectedItemIndex = pagination.getPageFirstItem() + getItems().getRowIndex();
        return "View";
    }

    public String prepareCreate() {
        current = new GuardProj();
        current.setGuardProjPK(new Entity.GuardProjPK());
        selectedItemIndex = -1;
        return "Create";
    }

    public String create() {
        try {
            current.getGuardProjPK().setUserTel(current.getUser().getUserTel());
            current.getGuardProjPK().setProjId(current.getProject().getProjId());
            getFacade().create(current);
            JsfUtil.addSuccessMessage(ResourceBundle.getBundle("/Bundle").getString("GuardProjCreated"));
            return prepareCreate();
        } catch (Exception e) {
            JsfUtil.addErrorMessage(e, ResourceBundle.getBundle("/Bundle").getString("PersistenceErrorOccured"));
            return null;
        }
    }

    public String prepareEdit() {
        current = (GuardProj) getItems().getRowData();
        selectedItemIndex = pagination.getPageFirstItem() + getItems().getRowIndex();
        return "Edit";
    }

    public String update() {
        try {
            current.getGuardProjPK().setUserTel(current.getUser().getUserTel());
            current.getGuardProjPK().setProjId(current.getProject().getProjId());
            getFacade().edit(current);
            JsfUtil.addSuccessMessage(ResourceBundle.getBundle("/Bundle").getString("GuardProjUpdated"));
            return "View";
        } catch (Exception e) {
            JsfUtil.addErrorMessage(e, ResourceBundle.getBundle("/Bundle").getString("PersistenceErrorOccured"));
            return null;
        }
    }

    public String destroy() {
        current = (GuardProj) getItems().getRowData();
        selectedItemIndex = pagination.getPageFirstItem() + getItems().getRowIndex();
        performDestroy();
        recreatePagination();
        recreateModel();
        return "List";
    }

    public String destroyAndView() {
        performDestroy();
        recreateModel();
        updateCurrentItem();
        if (selectedItemIndex >= 0) {
            return "View";
        } else {
            // all items were removed - go back to list
            recreateModel();
            return "List";
        }
    }

    private void performDestroy() {
        try {
            getFacade().remove(current);
            JsfUtil.addSuccessMessage(ResourceBundle.getBundle("/Bundle").getString("GuardProjDeleted"));
        } catch (Exception e) {
            JsfUtil.addErrorMessage(e, ResourceBundle.getBundle("/Bundle").getString("PersistenceErrorOccured"));
        }
    }

    private void updateCurrentItem() {
        int count = getFacade().count();
        if (selectedItemIndex >= count) {
            // selected index cannot be bigger than number of items:
            selectedItemIndex = count - 1;
            // go to previous page if last page disappeared:
            if (pagination.getPageFirstItem() >= count) {
                pagination.previousPage();
            }
        }
        if (selectedItemIndex >= 0) {
            current = getFacade().findRange(new int[]{selectedItemIndex, selectedItemIndex + 1}).get(0);
        }
    }

    public DataModel getItems() {
        if (items == null) {
            items = getPagination().createPageDataModel();
        }
        return items;
    }

    private void recreateModel() {
        items = null;
    }

    private void recreatePagination() {
        pagination = null;
    }

    public String next() {
        getPagination().nextPage();
        recreateModel();
        return "List";
    }

    public String previous() {
        getPagination().previousPage();
        recreateModel();
        return "List";
    }

    public SelectItem[] getItemsAvailableSelectMany() {
        return JsfUtil.getSelectItems(ejbFacade.findAll(), false);
    }

    public SelectItem[] getItemsAvailableSelectOne() {
        return JsfUtil.getSelectItems(ejbFacade.findAll(), true);
    }

    public GuardProj getGuardProj(Entity.GuardProjPK id) {
        return ejbFacade.find(id);
    }

    @FacesConverter(forClass = GuardProj.class)
    public static class GuardProjControllerConverter implements Converter {

        private static final String SEPARATOR = "#";
        private static final String SEPARATOR_ESCAPED = "\\#";

        @Override
        public Object getAsObject(FacesContext facesContext, UIComponent component, String value) {
            if (value == null || value.length() == 0) {
                return null;
            }
            GuardProjController controller = (GuardProjController) facesContext.getApplication().getELResolver().
                    getValue(facesContext.getELContext(), null, "guardProjController");
            return controller.getGuardProj(getKey(value));
        }

        Entity.GuardProjPK getKey(String value) {
            Entity.GuardProjPK key;
            String values[] = value.split(SEPARATOR_ESCAPED);
            key = new Entity.GuardProjPK();
            key.setProjId(Integer.parseInt(values[0]));
            key.setUserTel(values[1]);
            return key;
        }

        String getStringKey(Entity.GuardProjPK value) {
            StringBuilder sb = new StringBuilder();
            sb.append(value.getProjId());
            sb.append(SEPARATOR);
            sb.append(value.getUserTel());
            return sb.toString();
        }

        @Override
        public String getAsString(FacesContext facesContext, UIComponent component, Object object) {
            if (object == null) {
                return null;
            }
            if (object instanceof GuardProj) {
                GuardProj o = (GuardProj) object;
                return getStringKey(o.getGuardProjPK());
            } else {
                throw new IllegalArgumentException("object " + object + " is of type " + object.getClass().getName() + "; expected type: " + GuardProj.class.getName());
            }
        }

    }

}
